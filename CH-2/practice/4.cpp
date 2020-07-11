#include <iostream> 
#include <string> 
// 표준 라이브러리에서 가져와서 사용할 이름을 언급
using std::cin; using std::endl; using std::cout; using std::string; 
int main(void)
{
	// 사용자의 이름을 물음 
	cout << "Please enter your first name: "; 
	// 이름을 읽음
	string name; 
	cin >> name; 
	// 출력하려는 메시지 구성
	const string greeting = "Hello, " + name + "!";
	// 인사말을 둘러싼 공백의 개수 
	const int pad = 10;
	// 출력할 행과 열 개수 
	const int rows = pad * 2 + 3; 
	const string::size_type cols = greeting.size() + pad * 2 + 2; 
	// 단일 출력 표현식으로 공백 
	const string space(greeting.size() + pad * 2, ' '); 
	// 입력 부분과 출력 부분을 구분하려고 한 행을 건너뜀
	cout << endl; 
	// rows개 행을 출력합니다 
	// 불변성: 지금까지 r개 행을 출력 
	for (int r = 0; r != rows; r++) 
	{
		string::size_type c = 0;
		// 불변성: 현재 행에서 c개 문자를 출력 
		while (c != cols) { 
			// 인사말 출력 여부를 판별 
			if (r == pad + 1 && c == pad + 1) 
			{  
				cout << greeting;
				c += greeting.size(); 
			}
			else {
				// 테두리 출력 여부를 판별 
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
				{
					cout << "*"; ++c; 
				}
				else if (r == pad + 1) 
				{ 
					cout << " "; ++c; 
				}
				else 
				{
					cout << space; c += space.size();
				}
			}
		}
		cout << endl;
	}
	return 0;
}

//출처: https://jaimemin.tistory.com/1217 [꾸준함]

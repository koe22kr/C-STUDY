#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#define off
#ifdef on
int main()
{
	// ������ �ʱ�ȭ�� �̿��ؼ� string �� vector ����
	std::vector<std::string> myVector = { "A first string","A second string" };

	//��� string �� push_back �޼��带 �̿��ؼ� vector�� �߰�
	myVector.push_back("A third string");
	myVector.push_back("The last string in the vector");
	//push_back �� ���� ã�ƺ��� 09:12
	
	//���� ���� for ������ �̿��ؼ� �׸� ���.
	for (const auto& str : myVector)
		std::cout << str << std::endl;

	//�ݺ��ڸ� �̿��ؼ� vector�� ��ȸ�ϸ鼭 �� �� �� �׸� ���
	for (auto iterator = cbegin(myVector);
		iterator != cend(myVector); ++iterator) {
		std::cout << *iterator << std::endl;
		}
	
	return 0;
	   
	int i = 0, j = 0;
	int a = ((i++) + (++j));
	return 0;
}
#endif
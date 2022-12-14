/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:58:02 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/07 11:50:39 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base*	generate(void)
{
	int	random = std::rand();

	if (random % 3 == 0)
		return (new A);
	if (random % 3 == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base* p)
{
	/////////////////A///////////////////
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	/////////////////B////////////////////
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	/////////////////C////////////////////
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void	identify(Base& p)
{
	/////////////////A///////////////////
	try{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;}
	catch(const std::exception& e){}
	/////////////////B////////////////////
	try{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;}
	catch(const std::exception& e){}
	/////////////////C////////////////////
	try{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;}
	catch(const std::exception& e){}
}

int main()
{
	std::srand(std::time(0));
	Base*	a = generate();
	Base*	b = generate();
	Base*	c = generate();

	std::cout << "by addresse:" << std::endl;

	std::cout << "a = ";
	identify(a);
	
	std::cout << "b = ";
	identify(b);

	std::cout << "c = ";
	identify(c);

	std::cout << "by reference:" << std::endl;

	std::cout << "a = ";
	identify(*a);

	std::cout << "b = ";
	identify(*b);

	std::cout << "c = ";
	identify(*c);
	
	return (delete a, delete b, delete c, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:31:02 by ariahi            #+#    #+#             */
/*   Updated: 2022/12/03 22:44:19 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	const int			sign_grade;
	const int			exe_grade;
	bool				_signed;
public:
	Form();
	Form(const Form& other);
	Form(const std::string& Name, int Sign_grade);
	Form(const std::string& Name, int Sign_grade, int Exe_grade);
	virtual ~Form();

	Form&	operator=(const Form& other);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual	const char* what() const throw() { return "Grade too High";}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw() { return "Grade too Low";}
	};

	class NotSignedException : public std::exception
	{
	public:
		virtual const char * what() const throw() { return "Form not signed";}
	};

	const std::string	getName() const;
	int					getGrade() const;
	int					getExeGrade() const;
	bool				getSigned() const;

	void				beSigned(const Bureaucrat& bureaucrat);
	
	virtual void	execute( const Bureaucrat& executer) const = 0;
};

std::ostream&	operator<<(std::ostream& out, const Form& other);

#endif
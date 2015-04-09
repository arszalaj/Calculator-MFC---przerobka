#include "StdAfx.h"
#include "ONP.h"

#define _CRT_SECURE_NO_WARNINGS 1

CONP::CONP(void)
{
}

CONP::~CONP(void)
{
}

int CONP::getPrior(std::string op, int &assoc)
{
	assoc = LEFT_ASSOC;
	if(!op.compare("*") || !op.compare("/"))
		return 3;
	if(!op.compare("+") || !op.compare("-"))
		return 2;
	if(!op.compare("^"))
		return 4;

	return 0;
}
int CONP::getNextElement(string exp,string &buffer, int &position,bool ONP)
{
	buffer.clear();

	unsigned int i=position,j=0; // zmienne pomocnicze

	// pomijanie bia³ych znaków
	while(i < exp.length() && (exp[i] == ' ' || exp[i] == '\t'))
		i++;

	
	if(!isdigit(exp[i]) && exp[i] != '.') 
		
		if((i == 0 && (exp[i] == '-' || exp[i] == '+')) || (i > 0 && (exp[i] == '-' || exp[i] == '+') && ((exp[i-1] == ' ' || exp[i-1] == '(') && (i+1) < exp.length() && isdigit(exp[i+1]) )  ))
			i++; 
		else 
	{ 
		position = i+1; 
		buffer = exp[i]; 
		buffer+=' '; 
		if(exp[i] == '(') 
			return LB; 
		else if(exp[i] == ')') 
			return RB; 
		else 
		return OPERATOR; 
	}

	
	if(i < exp.length() && isdigit(exp[i]))
	{
	{
		
		if((i == 1 && (exp[0] == '-' || exp[0] == '+')) || ( i > 1 && (exp[i-1] == '-' || exp[i-1] == '+')  && (exp[i-2] == ' ' || exp[i-2] == '(')))
		{
			if((i == 1 && exp[0] == '-') || exp[i-1] == '-') 
				buffer += '-'; 
			else ; 
		}

		while(isdigit(exp[i])) 
			buffer+= exp[i++]; 
	}
	
	if(i < exp.length() && exp[i] == '.') 
		buffer+=exp[i++];
	while(i < exp.length() && isdigit(exp[i])) 
		buffer+=exp[i++]; 

	position = i; 
	buffer+=' '; 
	return NUMBER; 
	}
	position = i;
	return EOS; 
	           
}

int CONP::infixToONP(string infix,string &onp)
{
	CStack stack;
	int result;
	int position = 0;
	string buffer,buffer2;
	int assoc,assoc2;

	
	while(position < infix.length())
	{
		
		result = getNextElement(infix,buffer,position,0);

		switch(result)
		{
			case NUMBER: 
				onp += buffer;
				break;
			
			case OPERATOR : 
				while(stack.look(buffer2) && buffer2.compare("( ") && buffer2.compare(") ") &&
					(getPrior(buffer.substr(0,buffer.length()-1),assoc) <= getPrior(buffer2.substr(0,buffer2.length()-1),assoc2) 
					&& assoc == LEFT_ASSOC )
					|| getPrior(buffer.substr(0,buffer.length()-1),assoc) < getPrior(buffer2.substr(0,buffer2.length()-1),assoc2) 
					&& assoc == RIGHT_ASSOC )
				{
					stack.pop(buffer2); 
					onp+= buffer2; 
				}
				stack.push(buffer); 
				break;
			
			case LB:
				stack.push(buffer); 
			break;
		
			case RB :
				buffer2[0] = 0;
				while(buffer2[0] != '(') 
				{
					if(!stack.pop(buffer2)) 
						return ERROR; 
					if(buffer2[0] != '(')
						onp+= buffer2; 
				}
				break;

			case ERROR: 
				return ERROR;  
		}
	}

	while(stack.pop(buffer2))
		onp += buffer2;

	return 0;
}

int CONP::evaluateONP(std::string onp,long double &result)
{

	if(onp.length() == 0) 
	{
		result = 0; 
		return 0;
	}

	int position = 0;
	long double a,b,c;
	string buffer,buffer2;
	CStack stack;
	char buf[256];
	int res;
	
	while(position < onp.length())
	{
		res = getNextElement(onp,buffer,position,1);

		switch(res)
		{
			case NUMBER: 
				stack.push(buffer); 
				break;
			case OPERATOR: 
				if(buffer[0] == '+') 
			{

				stack.pop(buffer2); 
				a = atof(buffer2.c_str()); 
				memset(buf,0,256); 
				stack.pop(buffer2); 
				b = atof(buffer2.c_str()); 
				c = a+b; 
				sprintf_s(buf,"%.15lf",c); 
				buffer2 = buf;
				stack.push(buffer2);
			}
			if(buffer[0] == '-') 
			{

				stack.pop(buffer2); 
				a = atof(buffer2.c_str()); 
				memset(buf,0,256); 
				stack.pop(buffer2); 
				b = atof(buffer2.c_str()); 
				c = b-a; 
				sprintf_s(buf,"%.15lf",c); 
				buffer2 = buf;
				stack.push(buffer2);
			}
			if(buffer[0] == '*')
			{

				stack.pop(buffer2); 
				a = atof(buffer2.c_str()); 
				memset(buf,0,256); 
				stack.pop(buffer2); 
				b = atof(buffer2.c_str()); 
				c = a*b; 
				sprintf_s(buf,"%.15lf",c); 
				buffer2 = buf;
				stack.push(buffer2);
			}
			if(buffer[0] == '/')
			{

				stack.pop(buffer2); 
				a = atof(buffer2.c_str()); 
				memset(buf,0,256); 
				stack.pop(buffer2); 
				b = atof(buffer2.c_str()); 
				if(!a)
					return ERROR;
				c = b/a; 
				sprintf_s(buf,"%.15lf",c); 
				buffer2 = buf;
				stack.push(buffer2);
			}
			if(buffer[0] == '^')
			{
				stack.pop(buffer2); 
				a = atof(buffer2.c_str()); 
				memset(buf,0,256); 
				stack.pop(buffer2); 
				b = atof(buffer2.c_str()); 
				c = pow(b,a); 
				sprintf_s(buf,"%.15lf",c); 
				buffer2 = buf;
				stack.push(buffer2);
			}
			break;
		case ERROR: 
			return ERROR; 
			break;
		}
	}
	
	stack.pop(buffer2); 
	result = atof(buffer2.c_str()); 
}

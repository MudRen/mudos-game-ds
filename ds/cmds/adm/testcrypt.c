// passwd.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob;
	string input,seed,cryptcode,output;
	if(!arg) return notify_fail("�榡: testcrypt �s�X�r�� �ؤl�r��\n");
	if(sscanf(arg,"%s %s",input,seed)==2)
	{
		output="\ncrypt(\""+input+"\",\""+seed+"\") = ";
		cryptcode = crypt(input, seed);
	}
	else
	{
		output="\ncrypt(\""+arg+"\",\"0\") = ";
		cryptcode = crypt(arg, 0);
	}
	output += cryptcode+"\n";
	write(output);
	return 1;
}

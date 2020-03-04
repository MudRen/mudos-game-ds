// uptime.c

inherit F_CLEAN_UP;

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "�p��";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";

	write("[1;36m"+MUD_NAME+"[1;36m�w�g����F" + time + "[0m\n");
	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡 : uptime
 
�o�ӫ��O�i�D�A���C���w�g�s�����F�h�[.
 
HELP
    );
    return 1;
}

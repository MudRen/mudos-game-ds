// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : status [detail]
 
�o�ӫ��O�i�H��ܥX�ثe�C�����@�Ǭ�����ƤΪ��p.
 
HELP
    );
    return 1;
}
 

// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg || arg=="" ) return notify_fail("�A�n�����@���ޯ�S\n");

	if( !me->delete_skill(arg) )
		return notify_fail("�A�èS���ǹL�o���ޯ�C\n");
	if( arg == "combat" ) return notify_fail("�o�ӧޯ�L�k�ѰO�C\n");
	write("�A�M�w����~��ǲ�" + to_chinese(arg) + "�C\n");
	return 1;
}

int help()
{
	write(@TEXT
���O�榡�Rabandon <�ޯ�W��>

���@���A�ҾǪ��ޯ�A�`�N�o�̩һ����u���v�O���N�o���ޯ�q�A�H������Ƥ�
�R���A�p�G�A�w���٭n�m�A�����q 0 �}�l���m�A�аȥ��Ҽ{�M���C

�o�ӫ��O�ϥΪ����X�q�`�O�ΨӧR���@�ǡu���p�ߡv�m�X�Ӫ��ޯ�C
TEXT
	);
	return 1;
}

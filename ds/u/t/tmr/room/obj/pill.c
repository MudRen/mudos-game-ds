// black_pill.c
inherit ITEM;
void create()
{
	set_name("�Q�ߤ�", ({"black pill", "pill"}));
	if( !clonep() ) {
		set("unit", "��");
		set("long",
			"�Q�ߤ��O�@�إ����ܴ��M���Ĥ�M�Ψӫ�_�]�޽m�B�u�@�үӪ���O\n"
			"���������ĪG�M���I�O�Y�F�H��|�����H�H�Q��ı�M�B�e���f���C\n");
		set("unit", "��");
		set("value", 80);
		set("weight", 5);
	}
	setup();
}

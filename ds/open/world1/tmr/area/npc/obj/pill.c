inherit ITEM;
inherit F_PILL;
void create()
{
	set_name("�j�ɤ�", ({ "heal pill", "pill" }));
	set("long",@LONG
�j�ɤ��O�@�إ����ܴ��M���Ĥ�M�Ψӫ�_�]�޽m�B�u�@�үӪ���O
���������ĪG�M���I�O�Y�F�H��|�����H�H�Q��ı�M�B�e���f���C
LONG
);
	set_weight(300);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	}
        set("value", 240);
	set("heal",([ "hp" : 80, ]));
	setup();
}

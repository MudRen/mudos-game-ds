// dumpling.c

inherit ITEM;
inherit F_PILL;

void create()
{
	set_name("�U�F��", ({ "cure pill","pill" }) );
	set_weight(330);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�@���Ŧ⪺�p�ĤY�C\n");
		set("unit", "��");
		set("value", 80);	//�Ѧһ��欰�^�_�I���`�M���H5
		set("heal_hp",30);	//�i�H�O"heal_hp"�άO"heal_mp",
		set("heal_body",3);	//"heal_head" ,"heal_body"
		set("heal_head",3);	//"heal_hand" ,"heal_foot"�]�i�H����.
		set("heal_hand",2);	
		set("heal_foot",2);	
		//���ΰT�� eat_msg �i�H�� $N ���a, $n����.(�ж����|�ݨ�)
		set("eat_msg","$N�p���l�l���q�h�����X�@��$n, ���f���]�F�U�h�C");
		//�ĪG�T�� eff_msg ���i��$N �� $n (�]���u�����a�|�ݨ�)
		set("eff_msg","�Aı�o���骬�A��_�F���֡C");
	}
	setup();
}

// dumpling.c

inherit ITEM;
inherit F_PILL;

void create()
{
	set_name("�¥��_��Y", ({ "black jade pill","pill" }) );
	set_weight(110);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
�@���¦⤣�_�����p�ĤY�C
LONG
);
		set("unit", "��");
		//���ΰT�� eat_msg �i�H�� $N ���a, $n����.(�ж����|�ݨ�)
		set("eat_msg","$N�p���l�l���q�h�����X�@��$n, ���f���]�F�U�h�C");
		//�ĪG�T�� eff_msg ���i��$N �� $n (�]���u�����a�|�ݨ�)
		set("eff_msg","�Aı�o���骬�A��_�F���֡C");
	}
	set("value", 1500);
	set("cure",([
		"body" : 8,
		"head" : 8,
		"right_arm" : 8,
		"left_arm" : 8,
		"right_leg" : 8,
		"left_leg" : 8,
	]));
	set("heal",([
		"hp" : 100,
		"mp" : 50,
		"ap" : 50,
	]));
	setup();
}

#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("����", ({ "silk stocking","stocking" }) );
	set_weight(2100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@��¦⪺�����C\n[�i�x�s�˳�]\n");
		set("unit", "��");
		set("material", "silk");
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("value",180);
	}
	//============�H�U���q�}��ϰ�ť�, �_�h�|�j�V��===============
	//==    �Y�}��ϰ�n�g���ذ���eq , ���w�n�]�� Only One EQ    ==
	set("armor_prop/id",({"robber"}));
	set("armor_prop/name",({"�X���j�s"}));
	set("armor_prop/short",({"�X���j�s(Robber)"}));
	set("armor_prop/long",({"�@�ӥζ¿����n���Y���X���j�s�C\n"}));
	//==============================================================
	set("armor_prop/shield",15);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}

int query_autoload() { return 1; }
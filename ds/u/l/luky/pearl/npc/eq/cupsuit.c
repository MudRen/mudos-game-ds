// suit.c
// sorry sigma �j��. ���ɧڥΤ@�U!!
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
    set_name("ĵ���A", ({ "cup suit", "suit" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1100);
		set("material", "cloth");
       set("long",
"�o��s��[060989512]���`���A�ݰ_�ӫܴ��q, �W���٦��������C\n"
);
	}
	setup();
}
int fail_eq(object me)
{
if(me->query("int") <70)
{
  message_vision("$N�����O����, �L�k��W�C \n",me);
return 1;
}
set("armor_prop/dodge",20000);
set("armor_prop/armor",20000);
set("armor_prop/str",10000);
set("armor_prop/dex",10000);
set("armor_prop/lck",10000);
set("armor_prop/air",2);
set("armor_prop/con",10000);
set("armor_prop/mus",2);
set("armor_prop/int",10000);
set("armor_prop/wis",2);
set("armor_prop/id", ({"cup"}) );
set("armor_prop/name", ({"ĵ��"}) );
set("armor_prop/short", ({HIC"�o�c�g�P"NOR"  ĵ��(Cup)"}) );
set("armor_prop/long", ({@LONG

             / \
            |\_/|
            |---|
            |   |
            |   |
          _ |=-=| _
      _  / \|   |/ \
     / \|   |   |   ||\
    |   |   |   |   | \>
    |   |   |   |   |   \
    | -   -   -   - |)   )
    |                   /
     \                 /
      \               /
       \             /
        \           /
  �ݤ���!? ���n�v�T�ڿ�׳�!!
LONG
}));
return 0;
}
void init()
{
add_action("wear_suit","change");
add_action("rem_suit","unchange");
}

int wear_suit(string arg)
{
if(arg=="suit" ||arg=="all")
{
message_vision(HIC"$N�j�ۤ@�n:"HIY"�۸�!!"HIC" �����{�{�o�G�C\n"NOR,this_player());
 this_player()->set_temp("invis",1);
 set_temp("invis",1);
this_player()->set_temp("has_light",1);
set_temp("has_light",1);
}
}
int rem_suit(string arg)
{
if(arg=="suit" ||arg=="all")
{
message_vision(HIR"$N���W��ĵ�ˬ�M�z���}��!!\n"NOR,this_player());
 this_player()->delete_temp("invis");
}
}

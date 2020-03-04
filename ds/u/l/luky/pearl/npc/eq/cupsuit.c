// suit.c
// sorry sigma 大哥. 先借我用一下!!
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
    set_name("警察制服", ({ "cup suit", "suit" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 1100);
		set("material", "cloth");
       set("long",
"這件編號[060989512]的深色制服看起來很普通, 上面還有個徽章。\n"
);
	}
	setup();
}
int fail_eq(object me)
{
if(me->query("int") <70)
{
  message_vision("$N的智力不足, 無法穿上。 \n",me);
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
set("armor_prop/name", ({"警察"}) );
set("armor_prop/short", ({HIC"罪惡剋星"NOR"  警察(Cup)"}) );
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
  看什麼!? 不要影響我辦案喔!!
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
message_vision(HIC"$N大喊一聲:"HIY"著裝!!"HIC" 全身閃閃發亮。\n"NOR,this_player());
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
message_vision(HIR"$N身上的警裝突然爆裂開來!!\n"NOR,this_player());
 this_player()->delete_temp("invis");
}
}

#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("薔薇騎士劍", ({ "rose sword","sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把"); 
                set("limit_str",35);
                set("long", 
 "這把劍的劍鍔與劍柄像是薔薇莖幹一般長滿鐵刺，若是沒戴上護
  手肯定會握到手掌破皮，劍尖處則像是花瓣般的形狀，整體使用
  上增加了不少的力量。\n");
                set("value", 4000);
        }
        init_sword(56);
        setup();
}


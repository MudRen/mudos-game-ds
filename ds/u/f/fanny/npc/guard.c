#include <ansi.h>
inherit NPC;
void create()
{
        set_name( GRN"�ɿ��x�L"NOR , ({ "guard" }) );
        set("level",18);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set("long","�ɿ��������Ǫ��x�L�A�@�ƭ西�������ˤl�۵M���O�H�ͬȡC\n");
        setup();
        carry_object("/u/f/fanny/wp/gsword.c")->wield();
add_money("coin", 300);
}

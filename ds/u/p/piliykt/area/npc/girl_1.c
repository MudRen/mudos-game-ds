#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���Ѧt" , ({ "zhug-book-girl","girl" }) );
        set("level", 6);
        set("race","�H��");
        set("gender","�k��");
        set("age",18);
        set("int", 30);
        set("str", 10);
        set("con", 12);
        set_skill("parry", 5);
        set_skill("unarmed", 10);
        set_skill("dodge", 15);
        set("long",
   "�����ߤ@���k��, �ݰ_�Ӭ��R�ʤH,���ѹF§���ˤl�C\n");
        setup();
carry_object(__DIR__"eq/helmet_2.c")->wear();
        
}



#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "������", ({ "ghost staffer","ghost","staffer" , "__GUARD__"}) );
        set("level",30);
           set("combat_exp",3000);
set("exp",2000);
set("long","�L�O�խߦa�������ϧ�����A�b�\\�\\�h�h���ԧФ��A���F���ּĤH���j�N�C\n");
        set("age",50);
       set("evil",40);
                set("title",CYN"���X���S"NOR);
         set("gender","�k��");
                 set("attitude","killer");
           set_skill("staff",60);
          set_skill("dodge",60);
           set_skill("parry",60);
        set("Merits/wit",2);
        setup();
        carry_object(__DIR__"wp/staff.c")->wield();
}

#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIB "�ѤU�h�L" NOR , ({ "sky warrior","sky" }) );
        set("race", "�H��");
        set("age", 25);
        set("long","
���e���o��ѥS���S�����A�e�j�����A�[�W
��W�����j�M�p�����Z�ҡA�H�έI���e�j�����l�A
�O�H�������ߡA���D�L�N�O�j�N�ѤU���h�L�H\n");

        set("str", 80);
        set("cor", 80);
        set("dex",10);
        set_temp("apply/attack", 200);
        set_temp("apply/armor", 20);
        
        setup();
}        
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "�ѤU")
        {
say("�ѤU�h�L��A���D�G" HIY "�A�O�֡H�ڱq�ӨS���ݹL���A�o�˫Ӫ��H�F�H�C\n"NOR);
                command("finalhit" + me->query("id"));
        }else
         {
                say( HIY "�A�O�֡H \n" NOR );
                say( HIR "�ѤU�h�L�G�_�L���å�C \n" NOR );
                say( HIW "�ѤU�h�L���ʵ����l~~�n�j������:P�C\n"NOR);
                say( HIC "�ѤU�h�L�A�F�A�L���a�C\n" NOR );
      }   
}


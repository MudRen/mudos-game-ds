#include <ansi.h>
inherit ITEM;
void create()
{
            set_name(HIB"�j�����b�ɪ��޲z��"NOR,({"for no adm item","item"}) );
            set("unit","��");
            set("long",HIC"�o�O Jangshow ���F�]���S�H�޲z�� DS �Ҽg���C\n"NOR); 

       setup();
}
void init ()
{  
     add_action("do_jail","jail");
}
int do_jail(string z)
{
        object me,ob;
        me = this_player();
        if( !z )
        return notify_fail("�A�Q�n���� �S\n");
        if(!(ob = present(z, environment(me)))
        || !ob->is_character() || ob->is_corpse() )
        return notify_fail("�o�̨S���o�ӤH�C\n");
        if(ob==me)
        return notify_fail("�O�Q���}!\n");
        message_vision(HIC"\t$n�]���@���F�ơA�ҥH�Q$N���F�_�ӡC\n"NOR,me,users(),ob);
        call_out("gr",1,me,ob);
        return 1;
       }
void gr(object me,object ob)
{
if(!me) return; 
ob->set("out_of_power",1); 
ob->move("/open/always/ppl_jail"); 
ob->set("no_free",1);
ob->save();
return;
} 
int query_autoload() { return 1; }


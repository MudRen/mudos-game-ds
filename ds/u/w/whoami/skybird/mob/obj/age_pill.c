#include <ansi.h>
inherit ITEM;
void create()
{ 
  set_name(HIR"��"HIY"��"HIG"��"HIB"��"HIM"��"NOR, ({ "age pill","pill" }));
  set("long","�@���_�S�����ġA�A�Pı����o���ĩҴ��o�X�����M�`�𮧡E\n");
  set_weight(70); 
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",30000);
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env,*target; 
        int x;
        me = this_player();
        ob = this_object();
        target = all_inventory(environment(me));
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");

        if( me->is_fighting() ) me->start_busy(2);
        message_vision("$N�q�h�����X�F�@��"HIC"�C�m�ĤY"NOR"�A�H�Y�]�F�U�h�E\n" NOR,me);
        if( me->query("age") < 25 )
        {
                tell_object(me,WHT"�A�]�U�o���B�B���ĤY�A����èS�����ͤ����ܤơE\n"NOR); 
                destruct(ob);
                return 1;      
        } else {
                tell_object(me,HIY"�@�Ѯ�y���ħA���C�g�K�ߡA�餺����է������h�F����I�I\n"NOR);
                message_vision("$N�o�X�@�n�G�s�A���W���F�L�h�E\n",me);
                me->unconcious(); 
                  me->set("age_modify",-1);
                me->set("hp",1);
                me->set("mp",1);                
                me->set("ap",1);
        destruct(ob);
        } 
        return 1;
}


#include <ansi.h>
inherit ITEM;

string *all_oppmobs = ({
__DIR__"evil7"});
void create()
        {
         set_weight(5);
         set_name(HIW"���ձ��b"NOR,({"test book","book"}));
         set("value", 1);
         set("long", "�@�̤��ԡA�ѥ֤W���G���ǦǹСA�����O�_�i����(clean)�@�U�H\n");
         set("unit", "��");
         setup();
}

void init()
{
        add_action("do_clean","clean");
}

int do_clean(string arg)
{
  object me = this_player();
  object ob,env;

        if(! env = environment(me)) return 0;
        if( !env->query("outdoors") )
                return notify_fail(HIW"��M���ѤO�q���A�L�q�U��C\n"NOR);
        if(!arg||arg!="book") return notify_fail("���O���~�A�ЦA��J�@��!!\n");
        switch (random(2) ){ 
                case 0:
       message_vision("$N�����F�ѤW���ǹСA���@�L�ܤơI�I\n", me);
                       me->start_busy(2); 
                       destruct(this_object());
                      break;
               case 1:
          ob= new(all_oppmobs[random(sizeof(all_oppmobs))]); 
          message("world:world1:vision",
        HIY"\n\t\t�����������M�����@�{�A���G���Ǥ����R�C\n\n"NOR
        ,users() );
          message_vision(HIG"$N"HIW"�����F�ѤW���ǹЫ�A�ðΦb�Ѥ��̪�"NOR"$n"HIW"�Ǧ����|«�k�ӥX�I�I\n"NOR, me, ob);
          ob->move(environment(me));
          break;          }
          destruct(this_object());
          return 1; 
}


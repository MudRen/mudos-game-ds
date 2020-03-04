#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"�}�ª���c"NOR,({"old box","box"}));
        set("unit", "��");
        set("long",@LONG
�@�ӧG���j������}�½c�l�A���Y���w�g�G���F�A�]�\�V�@�U�N�|���}�F�C
LONG
        );
        set_weight(999999);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_openbox","hit");
}

int do_openbox(string arg)
{
        object obj,me = this_player();
        object room = environment(this_player());
        if(arg != "old box" && arg != "box" && arg != "wood")
          { return notify_fail("�A�n���}����H\n"); }
        if(!me->is_busy() || me->is_fighting())
          { 
              message_vision(HIY"$N�յۺV�}��c...\n"NOR,me);
              me->start_busy(7);
              call_out("open",5);
              return 1;
          }
        else
             { return notify_fail("�A���b���I\n"); }
}

void open()
{
        int i,ran,index,amount;
        string msg;
        object obj;
        object ob = this_object();
        object me = this_player();
        
        i = random(100);
        ran = random(10); 
        switch( i ) {
           case 0..5:
                   message_vision(HIR"$N�V�}��c�A���L�̭�����]�S��...\n\n"NOR,me);
                   destruct(ob);
                   break;
           case 6..10:
                   message_vision(HIR"$N�V�}��c�A�s�F�@�n�G�F...�Ū��I\n\n"NOR,me);
                   destruct(ob);
                   break;
           case 11..100:
                   message_vision(HIR"��c�Q$N�V�}�F�I\n\n"NOR,me);
                   switch( ran ) {
                      case 0:
                             amount = random(20000)+1;
                             obj =  new("/obj/money/coin");
                             obj->set_amount(amount);
                             msg = "���X"+chinese_number(amount)+"�T�j��";
                             obj->move(environment(me));
                             break;
                      case 1:
                             index = random(50)+1;
                             msg = "���X"+chinese_number(index)+"�J�|����";
                             for(i=0;i<index;i++)
                               new("/open/world1/acme/area/npc/obj/soup")->move(environment(me));
                             break;
                      case 2:
                             index = random(30)+1;
                             msg = "���X"+chinese_number(index)+"��"+HIY"����³��"NOR;
                             for(i=0;i<index;i++)
                               new("/open/world1/moonhide/pool/npc/obj/lbg")->move(environment(me));
                             break;
                      case 3:
                             index = random(30)+1;
                             msg = "���X"+chinese_number(index)+"������Y";
                             for(i=0;i<index;i++)
                               new("/open/world1/ksj/east_island/npc/eq/genki-pill")->move(environment(me));
                             break;
                      default:
                             index = random(4)+1;
                             obj = new("/u/f/fedex/area/npc/npc1");
                             message_vision(HIR"�c�l�̽ĥX"+chinese_number(index)+
                             obj->query("unit")+obj->query("name")+"�I\n"NOR,obj,me);
                             for(i=0;i<index;i++)
                               new("/u/f/fedex/area/npc/npc1")->move(environment(me));
                      break;
                      }
                      if (ran <=3)
                       { message_vision("\n�c�l��"+msg+"�A�ӯ��_�F�I\n\n",me); }
                      destruct(ob);
            break;
          }
}


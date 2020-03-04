#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("�`�}", ({"hole"}) );
        set("long",@LONG
�@�Ӽe���T�ءA�`���������a�}�A���ɦ��j�P����y�i�X�a�}�A���O
�b�I�l�����A�γ\�i�H��F��U�h�ݬݦ��������(throw �Y��)�C
LONG
        );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "��");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
        add_action("do_throw","throw");
}

int do_throw(string str)
{
        object me,b,z,ob;
        me=this_player();
 
        if(!str || str!="heart") return 0;
        if(!objectp(z=present("silver dragon heart",me) ) )
        return notify_fail("�A�S���F��i�H��� ? \n");
       
        // 1/13 �s�W by ksj
        ob=find_living("_NPC_BLOOD_EYE_DRAGON_");
        if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N�N�@�󪫨ƥ�J�`�}���A���S��������R�C\n",me);
            destruct(z);
            return 1;
          }
        }
  
        destruct(z);
        message_vision(
        HIW"\n$N�N�@�󪫨ƥ�J�`�}���A�H��}���_�X�����շϡC\n"NOR
        HIR"\n��M�a���Y��½�_�A�@�ӥ��j�����v�q�a���_�F�X�ӡI\n"NOR,me);
        message("world:world1:vision",
        HIR"\n\t"HIG" ��@�q "HIR"�W��M�@�}�s�n�a�ʡA�W�j�h�a�U���c�s�A���d���I�I\n\n"NOR
        ,users());
        b=new(__DIR__"npc/blood-eye-dragon" );
        b->move(environment(this_object()));
        destruct(this_object());
        return 1;
}

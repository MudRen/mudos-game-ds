#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
        set_name("���]�x", ({"fon-mo table"}) );
        set("long",@LONG
�����x�O�ʦL��d�~���~�w�d�~�u�b�һs���Ať�������]�x�O�X��
�k�O���`�������t���Ӫ�ƤQ�~���׬��������ܰ����]�x�A���Oť
���u�n���@�˯�\�L�t�A���M�t�𪺪��~�A�K�����j�c���j���d
�j���~�ѩ�A���O�ܤ��Ҧ����Z�L�P�D�H�h�N�⪾�D�ѩ�d�j���~
�����~�A�]���������C���~�o���]�x�������@�W�_���G���@�ɤp
�ۤl��J(putting xxxx)LONG
        );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1);
        set("unit", "��");
        set("volume",10000);
        set("value",0);
        }
        setup(); 
}

void init()
{
        add_action("do_putting","putting");
}

int do_putting(string str)
{
        object me,b,z,ob;
        me=this_player();
 
        if(!str || str!="stone") return 0;
        if(!objectp(z=present("evil stone",me) ) )
        return notify_fail("�A�èS���۳�d�j���~����!! \n");
        ob=find("__DIR__"npc/aeonian-beast.c");
         if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N��H�x���c���N��������U�W�Ѹ̡A���O�@�I���R�]�S��!?\n",me);
            destruct(z);
            return 1;
          }
        }
  
        destruct(z);
        message_vision(
        HIR"\n$N�N���c�N���u���c�ۡv����i�W�ѡI�I�C\n"NOR
        HIG"\n���趡�A�ƹD�����ﭱ�ӥX�I�I\n"NOR 
        HIW"\n�j�a��M�����ܦ�I�I\n"NOR,me); 
        message("world:world1:vision",
        HIR"\n\t�d�j���~ �d"NOR"�~�u"HIM"�b"HIW"�g�L�F�d�~���I�ΡA�A�׭��{�󤤭�I�I\n\n"NOR
        ,users());
        b=new(__DIR__"npc/aeonian-beast.c" );
        b->move(environment(this_object()));
        destruct(this_object());
        return 1;
}


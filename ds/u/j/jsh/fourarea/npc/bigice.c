#include <ansi.h>
inherit ITEM;
        
void create()
{
        set_name("�d�~�z�B", ({"thousand ice","ice"}) );
        set("long",@LONG
�o�O�@���ܤj�����B�A�����������v�A�����٦��@�������_�ͬ}
���� (put xxx)�A�o���B�����ūצ��G�ܧC�A�����D������F�� 
�i�H��o���B���ĤơA�Ѷ}�B�����������C(kok xxx)
LONG
        );
        set_weight(1000);
        set_max_capacity(10);
        set_max_encumbrance(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_get",1);
        set("no_drop",1); 
        set("no_sac",1);      
        set("unit", "��");
        set("volume",5000);
        set("value",123);
        }
        setup(); 
}

void init()
{
        add_action("kok_ice","kok");
        add_action("put_key_of_fire","put");
}

int put_key_of_fire(string str)
{
        object me=this_player();
        object ob;

        if(str=="key of fire")
        {
        if(!ob=present("key of fire",me))
                {return notify_fail("�A�n�񤰻�F�裫 ???\n");}

        if(this_object()->query_temp("key of fire")==1)
                {
                write("�A�w�g�}�L�F \n");
                return 1;
                }
                destruct(ob);
                message_vision(
                HIR"$N�N���V���_��i�d�~�z�B���ͤո̡A�u�����V���_�����z�N�A�d�~�z�B���G���F�}�ӡC\n"NOR,me);
                set_temp("key of fire",1);
                return 1;
        }

}

int kok_ice(string str)
{
        if(this_object()->query_temp("opened") != 0) return 0;
        
        if(str=="ice")
        {
        object me,b;
        me=this_player();

        message_vision(
        HIW"\n$N���d�~�z�B�������I�V�F�V . . . �d�~�z�B��ӸH�}�I\n"NOR,me);

         if(this_object()->query_temp("key of fire")==1)        
         {
          message_vision(
          HIW"�Ѫŭ��U�F������"HIC"���� \n"NOR,me);

          b=new(__DIR__"ice.c" );
          b->move(environment(this_object()) );
          delete_temp("key of fire");
          //set_temp("opened",1);
          return 1;
          }
        else
          {
          message_vision(
          HIG"$N���@�ӧb�l�@��...�����D�b�F���C\n"NOR,me);
          }
        return 1;
        }
}


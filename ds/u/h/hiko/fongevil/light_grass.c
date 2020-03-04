inherit ITEM;

void create()
{
        set_name("�G�ï�",({"light grass","grass"}));
        set("long",
            "�@�س��w�ͦs�b�·t�a�誺�Ӫ��A�ӥB�_�S���O\n"
            "���ٷ|�o�X�å��A�ô��o�@�دS�����l�ޥͪ�\n"
            "���񥦡A�����ؤl�O�����ƪ��n���ơA�i�O�ܤ�\n"
            "���G�A�A�i�H�K�ݬ�(tug)\n");
        set_weight(9999);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("no_get",1);
        }
        setup();
}

void init()
{
        add_action("do_tug","tug");
}

int do_tug(string arg)
{
        object me=this_player(),grass,obj=this_object();
        grass = new(__DIR__"item/grass_berry");
        if( arg !="light grass" && arg !="�G�ï�" )
                return notify_fail("�A�n�K����F��r�H\n");
        else if( !obj->query_temp("get_berry")) 
               {
                message_vision("$N�Τ��G�ï󪺺ؤl�K�F�U�ӡC\n",me);
                obj->set_temp("get_berry",1);
                grass->move(me);
                call_out("delay",9000);
               } 
           else {
                message_vision("$N�Q�Τ�K�G�ï󪺺ؤl�A�o�Q��W�����ˤF�C\n",me);
                me->receive_damage("hp",5);
                }
         return 1;
}

void delay()
{
     object ob=this_object();
     if(!ob) return; 
     ob->delete_temp("get_berry");
}



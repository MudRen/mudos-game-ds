#include <ansi.h>
inherit ROOM;


void create()
{
        set("short", "�t����");
        set("long", 
HIR"                  �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"
HIR"�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"
HIR"      �i�i�i�i�i�i                                �i�i�i�i�i�i\n"
HIR"      �i�i�i�i�i�i              "HIC"�t����"HIR"            �i�i�i�i�i�i\n"
HIR"      �i�i�i�i�i�i                                �i�i�i�i�i�i\n"
HIR"�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"
HIR"  �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"
HIR"  �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i���i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"
HIR"�i�i�i�i�i�i�i  �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i  �i�i�i�i�i�i�i\n" 
HIR"�i�i�i�i                        �i�i�i                        �i�i�i�i\n"
HIR"�i�i                            �i�i�i                            �i�i\n"
HIR"�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i          �i�i�i�i�i�i�i�i�i�i�i�i�i�i�i\n"NOR
        );

        set("item_desc",([
        "��}":"�t�������������p�}�A�����D������@�ΡA�n���i�H�઺�ˤl(turned x on x)�C\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "north" : "/open/world1/ground_temple/room-22",
        ]));
        set("world", "past");
        setup();
}
void init()
{
        add_action("do_turn","turned");
}

int do_turn(string arg)
{
        object me,mir;  
        me=this_player(); 
        if(this_object()->query_temp("CALLED")==1) return notify_fail("���w�g���H��L�F�C\n");
        if(!arg || arg!="mirror on ��}") return notify_fail("�A�n turned ����?\n");
        if(!objectp(mir=present("turn dragon-mirror",me) ) )
                return notify_fail("�A�S���F��i�H��ʰ� ? \n");
        message_vision("$N�N���s���i�F��}�̡A�b���s������������A�a��������M�}�l�n�ʤF�C\n",me);
        message("world:world1:vision",HIW"\n\t���������E�E�E�E\n"
                                    +HIR"\n\t�@�}�ѷn�a�ʫ�A�ǻ������a�s�A�X�{�b�a�������F�I\n\n"+NOR,users()); 
        destruct(mir);
        me->start_busy(2);  
        //this_object()->add_temp("CALLED",1); 
        //call_out("DE_CALLED",1000,me);
        call_out("BRING",3,me);    
        return 1;        
} 
void BRING()
{
     object me=this_player(),MOB;
     MOB=new(__DIR__"npc/dragon");
     MOB->move(environment(this_player()));
     MOB->kill_object(environment(me));
     message_vision(HIW"��M�@�D"+HIG"�C���z�g"+HIW"�I���V"+(string)me->query("name")+"�I\n"+NOR,me);
     me->receive_damage("hp",this_player()->query("max_hp")/2); 
     return;
}  
/*void DE_CALLED()
{    this_object()->delete_temp("CALLED",1); return;      } 
*/

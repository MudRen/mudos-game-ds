#include <ansi.h>
inherit ROOM;
void show(object me);
void create()
{
       set("short", HIG"�p�ˮ�"NOR);
       set("long",@LONG
�o�̮������p�ˮ�..�A�Τߪ���ť�ۤp�˪��y���n..�߱����R�F�\�h...
LONG
        );
       set("item_desc",([
 "�p�ˬy":"�@���F�F���p�ˬy..���H�@�ئw�����M���Pı,�A��M�o�{�̭��n��������ͪ��b��..�C\n",
 "�p�ͪ�":"�@��"HIR"����"NOR"���ͪ�..�ݰ_�ӫܦn�Y���ˤl�A�A�γ\\�i��䳨��N�e��(angle)�_�� �C\n",
 "�p��":"�o���p���i�H��(goin)�^���H��C\n",
 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}
void init()
{
 add_action("do_angle","angle");
 add_action("do_goin","goin");
}
int do_angle(string arg)
{
        object me,ccc;
        me = this_player();
        if( !arg ) return 0;
        if( arg!="�p�ͪ�" )
      {
                notify_fail("�A�n������F��?\n");
                return 0;
      }
if( query_temp("anglelobser") )
{
    return 0;
}
if(!objectp(ccc=present("rod",me) ) )
return notify_fail(HIC"�S������n��򳨪F��?�C\n"NOR);
message_vision(HIG"$N���_����ϤJ�F�p�˸̡C\n"NOR,me);
        me->start_busy(8);
        call_out("no",3,me);
        call_out("no2",5,me);
        call_out("delay",1800,this_object());
        return 1;
}
void no(object me)
{
     if(!me) return;
     message_vision(HIC"��M�@�}����..$N����԰_����C\n"NOR,me);
     return;
}
void no2(object me)
{
     object ll;
     ll=new(__DIR__"obj/lobser");
     message_vision(HIY"$N�ש󳨥X�F�����p�ͪ�..�~�M�@�ݳ��M�O�@���j�j"HIR"����"NOR"���s��..�C\n"NOR,me);
     ll->move(me); 
     set_temp("anglelobser",1);
     this_object()->delete("item_desc");
     set("item_desc",([
 "�p�ˬy":"�@���F�F���p�ˬy..���H�@�ئw�����M���Pı�C\n",
]));
}
void delay(object room)
{
  delete_temp("anglelobser");
  set("item_desc",([
 "�p�ˬy":"�@���F�F���p�ˬy..���H�@�ئw�����M���Pı,�A��M�o�{�̭��n��������ͪ��b��..�C\n",
]));
        return;
}

int do_goin(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="�p��") return 0;
        message_vision("$N�}�}�ߤߪ����p�����F�^�h...�C\n",me);
        me->move(__DIR__"map_2");
        tell_room(environment(me),me->query("name")+"�q�p�������F�L�ӡC\n",({ me }) );
        return 1;
}


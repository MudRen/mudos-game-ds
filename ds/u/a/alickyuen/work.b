#include <ansi.h>

inherit ROOM;
void welcome(object ob,int i);

void create()
{
        set("short", "�T����");
        set("long",@LONG
�o�̬O�ѵ��K�@�ͤj�H�o�b�B�c�Q�B�𮧪��a��A�b�o�̧A�u��
��@�ӪO�l�A�W���g�ۡG�y�Фť��Z�A���W���}�I�z���r�y�C
LONG);
        set("valid_startroom", 1);
        set("no_kill", 1);
        set("no_fight", 1);
        set("exits",([
             "east" : "/d/wiz/hall1.c",
        ]));
        setup();
}
void init()
{
        object me;
        me=this_player();
//        if(me->query("id") != "alickyuen" && wiz_level(me) < 4 && userp(me) )
        if(me->query("id") != "alickyuen" )
                welcome(me,1);
         else welcome(me,2);
}
void welcome(object ob,int i)
{
        if( i == 1 )
        {
                ob->move(__DIR__"workroom3");
                tell_object(ob,RED"�y�Фť��Z�A���W���}�I�z\n"NOR);
        }
        else 
        {
//                ob->set("nickname",RED"�T����"NOR);
                tell_object(ob,YEL"�y�w����{�I�z\n"NOR);
        }
        return;
}


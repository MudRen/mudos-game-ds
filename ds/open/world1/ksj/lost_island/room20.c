#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q�Фs��");
        set("long", @LONG
�o�̦��s�������@�B�W���A�s�W�̭����M�O�@�j���B���A�z�L
�B�������i�H�ݨ��B���᭱�O�@�Ӥj�s�}�A�q�s���̭������y�X�M��
�B�D�����A�׻E���@���p�ˡA�y�V���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room19",

]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("item_desc",([
        "�B��":"�i�H�յۥ��H��(hit)�C\n",
        ]));

        setup();
}

void init()
{
        add_action("hit_wall","hit");
}

int hit_wall(string str)
{
        if(this_object()->query_temp("opened") != 0) return 0;
        
        if(str=="�B��")
        {
        object me;
        me=this_player();
        if(me->query_str()<50 ){
        message_vision(HIR"\n$N�@�����V�B���A--�n-- �@�n�T�A�B�������L�l�A�u�d�U�H�H���C\n"NOR,me);
        me->receive_damage("hp",30,this_object());
        return 1;}
        message_vision(
        HIW"\n$N�r�O�@�����V�B���A--��-- �@�n�T�A�B���y�ɦ��H���@�a���B���C\n"NOR,me);
        set("long", @LONG
�o�̦��s�������@�B�W���A�s�W�̭��O�@�Ӥj�s�}�A�q�s�}��
�ǥX�������H��A�q�s���̭������y�X�M���B�D�����A�׻E���@���p
�ˡA�y�V���C
LONG
        );
        
        set("item_desc",([
        "�B��":"�B���w�g�Q���H�F�C\n",
        ]));

        set("exits", ([
        "east" : __DIR__"room19",
        "enter" : __DIR__"room21",
   
        ]));
        
        set_temp("opened",1);
        return 1;
        }
}

void reset()
{
        set("long", @LONG
�o�̦��s�������@�B�W���A�s�W�̭����M�O�@�j���B���A�z�L
�B�������i�H�ݨ��B���᭱�O�@�Ӥj�s�}�A�q�s���̭������y�X�M��
�B�D�����A�׻E���@���p�ˡA�y�V���C
LONG
        );
        set("exits", ([
        "east" : __DIR__"room19",
        ]));
        set("item_desc",([
        "�B��":"�i�H�յۥ��H��(hit)�C\n",
        ]));
        delete_temp("opened");
        ::reset();
}

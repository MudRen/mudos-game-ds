#include <ansi.h>

inherit ROOM;

int doll_check(object me);
int check(object me);
void create()
{
        set("short", "MOB���հϰ�X�f");
        set("long", @long
�o�̬O���եX�h���X�f�ݤJ�f�A�Z�O�n�i�J�ΥX�h�A���o�q���X
�i�X�C�n���}�Х�"out"�A�n�������մ����������ܡA�Щ������p��
�U�������C
long);
        set("light", 1);
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_cast", 1);  
        set("objects", ([ /* sizeof() == 1 */
      "/u/p/promise/lady": 1,
]));   set("exits", ([ /* sizeof() == 2 */

  "east" : __DIR__"testroom1",
])); 
        setup();
}

void init()
{
        object me = this_player();

        if( !me ) return;

        add_action("doll_check", "out");
        add_action("doll_check", "quit");
                return;

        check(me); 
        doll_check(me);}

int doll_check(object me)
{
        object doll;
        me = this_player();
        message_vision(HIW"�����p���U���b�ˬd$N���W���S�����եΪ���������.....\n"NOR, me);

        if( objectp(doll = present("test doll", me) ) )
        {
                message_vision(HIW"�����p���U��"+me->query("name")+"���W��"NOR+doll->query("name")+HIW"�����F�C\n"NOR, me);
                destruct(doll);
        } 
                me->move("/open/world1/tmr/area/hotel");
        return 1;
}


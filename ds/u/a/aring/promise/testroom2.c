#include <ansi.h>

inherit ROOM;

int doll_check(object me);
int check(object me);
void create()
{
        set("short", HIC"�iMOB���հϰ�B�ϡj"NOR);
        set("long", "\n
����B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���B��
����B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���
B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���B�ϴ���B��
\n"NOR);
        set("light", 1);
       set("exits", ([ /* sizeof() == 2 */
   "west" : __DIR__"testroom1",
]));  
       set("outdoors","land");        setup();
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
        message_vision(HIW"�����p���U�j���ˬd$N���W���S�����եΪ���������.....\n"NOR, me);

        if( objectp(doll = present("test doll", me) ) )
        {
                message_vision(HIW"�����p���U�j�ŧ�"+me->query("name")+"���W��"NOR+doll->query("name")+HIW"�����F�C\n"NOR, me);
                destruct(doll);
        } 
                me->move("/open/world1/tmr/area/hotel");
        return 1;
}



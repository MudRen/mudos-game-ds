#include <ansi2.h>
inherit ROOM;

void create()
{
        set("short", "�@�ɤ���");
        set("long", @LONG
none none none none none none none none none none 
none none none none none none none none none none none
none none none none none none none none none none none
none none none none none none none none none none none
(help stone) (through)
LONG
        );
        set("item_desc",([
        "�]�k��":"help stone\n",
        ]));
        set("no_clean_up", 0);
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"workroom",
        ]));

        setup();
}
void init()
{
        add_action("do_help","help");
}
int do_help(string str)
{
        if(str != "stone") return 0;
        write(HIW"�A�n��V(through)����@�ӮɪšH\n"NOR);
        add_action("do_through","through");
        return 1;
}
int do_through(string str1)
{
        if(!str1)
        {
        message_vision(
        HIW"�{�b���G\n\n"NOR
        HIY"1.�Y�s��\n\n"NOR
        HIY"2.���s�j�Q�r\n\n"NOR 
        HIG"Please use�ythrough with number�z\n"NOR,this_player()
        );
        return 1;
        }
        if(str1 =="1")
        {
        message_vision(
        HIW"$N�N�����b�]�k�ۤW�A�j�ۡG�Y�s�� !!\n"NOR
        HIW"�ե��@��A$N�����������F�C\n"NOR,this_player()
        );
        
        this_player()->move(__DIR__"dragonarea/startroom.c");
        return 1;
        }
        if(str1 == "2")
        {
        message_vision(
        HIW"$N�N�����b�]�k�ۤW�A�j�ۡG���s�j�Q�r !!\n"NOR
        HIW"�ե��@��A$N�����������F�C\n"NOR,this_player()
        );
        
        this_player()->move(__DIR__"dragonarea/room_6.c");
        return 1;
        }
        else
        {
        write(HIW"�n�h"+str1+HIW"�ۤv�h�a....\n"NOR);
        }
        return 1;
}



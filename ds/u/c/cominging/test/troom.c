//
//      �ھڤѮ�ӧ��ܩж��� long ���зǩж�
//
//                                                      Create by Caesar

#include <mudlib.h>

inherit ROOM;

#define CONTROL_DAEMON  "/u/c/caesar/temp/tmob"         // ���s�ж��ԭz������

mapping room_long = ([
                "day"   : "�դѪ� long \n",
                "night" : "�ߤW�� long \n" 
                        ]);

void change_long(string status)
{
        switch(status)
        {
                case "�դ�" :
                        set("long", room_long["day"] );
                        return;

                case "�ߤW" :
                        set("long", room_long["night"] );
                        return;

                default :
                        return;
        }
}

void create()
{
        object daemon;
        ::create();
        seteuid(getuid());
        set("long", "�쥻�� LONG\n" );
        set("short", "�쥻�� SHORT" );
        set("light", 1 );

        // �p�G�٨S���J�N���J�a
        if( daemon = find_object_or_load(CONTROL_DAEMON) )
                change_long(daemon->query_weather_status());
}

#include <ansi.h>;
inherit __DIR__"room";
void create()
{
        set("short", HIC"�������j��"NOR);
        set("long", "
"HIM"�����@�@�����@�@�����@�@�����@�@�����@�@�����@�@�����@�@����
�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i�@�@�i�i
�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i�i"HIY"�m�������j���n"HIM"�i�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i�i�h�h�h�h�h�h�h�i�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i"HIC"��"HIM"�i�@�@�@�@�@�i"HIC"��"HIM"�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i"HIW"��"HIM"�i�@�@�@�@�@�i"HIW"�s"HIM"�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i"HIW"�L"HIM"�i�@�@�@�@�@�i"HIW"��"HIM"�i�i�i�i�i�i�i�i�i�i�i
�i�i�i�i�i�i�i�i�i�i"HIW"�P"HIM"�i�@�@�@�@�@�i"HIW"��"HIM"�i�i�i�i�i�i�i�i�i�i�i
���i�i�i�i�i�i�i�i�i�i�i�@�@�@�@�@�i�i�i�i�i�i�i�i�i�i�i�i��"NOR"
");
        set("exits", ([ 
  "south" : __DIR__"room2",  
  "enter" : __DIR__"room8",  
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/guard" :2,
]));
        set("light",1);
        setup();
}


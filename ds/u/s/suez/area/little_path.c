#include <ansi.h>
inherit ROOM;

void create()
{
 set("short",HIB"密道"NOR);
        set("long",
HIB"一個陰暗的密道，雖然聽的見水聲，但是卻十分乾爽。\n"
        );
        set("light",1);
        setup();
 }
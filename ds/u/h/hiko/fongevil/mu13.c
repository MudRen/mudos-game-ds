inherit ROOM;
void create()
{
        set("short", "半山腰");
        set("long",@LONG
這裡已經是半山腰了，在你眼前有著一間草屋，雖然極為簡樸卻很
堅固，可以看得出來建造的人手藝之精巧，附近花草修剪整齊，看來非
常讓人感覺舒服，住在此地的人該很愛清雅，南邊的路通往山下。
LONG
        );
  
set("exits", ([
  "enter" : __DIR__"yu_home",
  "southdown" : __DIR__"mu12",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 






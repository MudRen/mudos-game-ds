inherit ROOM;

void create()
{
        set("short", "軍牢");
        set("long", @LONG
這裡是專門抓放不法人仕，或是觸犯軍法的人，四周一片漆黑
，只有一小盞的油燈，像風中殘燭一樣，快要熄滅的樣子。
LONG
        ); 
        set("no_get",1);
        set("no_drop",1);
        set("no_exert",1);
        set("no_cast",1);
set("light",1);
        set("no_clean_up", 0);

        setup();
}


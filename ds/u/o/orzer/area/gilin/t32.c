inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
你慢慢的朝向森林深處走去，在你眼前有著奇怪的人形生物，身上
傳出一陣陣腐肉味道，行動十分緩慢，而且雙眼無神身上毫無半點生氣
，不知道是什麼奇怪的東西，霧氣漸漸轉為濃厚。
LONG
        );
        set("exits", ([
        "southeast" : __DIR__"t36",
        "northwest" : __DIR__"t33", 
        "northeast" : __DIR__"t31",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














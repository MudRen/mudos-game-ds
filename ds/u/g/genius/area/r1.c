inherit ROOM;

void create()
{
set("short","農舍");
        set("long", @LONG
這是一間普通的農舍。房舍的一角堆滿了爐薪，還擱了一把斧頭。另一
角則是一籃又一籃剛採收的桃子，個個豐盈飽滿，似乎非常的香甜。
LONG
        );
        set("exits", ([
        "west":__DIR__"al3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

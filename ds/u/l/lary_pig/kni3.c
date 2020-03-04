inherit ROOM;

void create()
{
        set("short", "那魯雷斯騎士團 - 武器收藏室");
        set("long", @LONG
這裡是那魯雷斯騎士團收藏及放置武器、防具的地方，在這個寬
闊的空間內，四周排滿了許多優良的武器及防具，而那些資格老練的
皇家騎士們，也會時常擺放一些裝備在這地方，以方便一些能力較弱
的騎士們取用。
LONG
        );

        set("exits", ([
  "east" : "/u/l/lary/workroom",
        ]) );
        set("light",1);
        set("no_fight",1);
        set("no_kill",1);
        setup();
}


inherit ROOM;

void create()
{
 set("short","雜草叢");
        set("long",@LONG
這堆雜草叢也不知道延伸到哪裡，其中連個小樹都沒有，走進去的人
想不迷路都難，不過仔細一看，亂草之中似乎有棟建築物，又好像不是。
正當你想轉身離開時，突然覺得好像有什麼地方不對，這些雜草，似乎不
太自然，莫非真的有人......？
LONG
        );

         set("exits", ([
         "west": __DIR__"path_t",
         "southeast": __DIR__"seven_d1",
         "northeast": __DIR__"seven_l1",
         ]));
        
        set("outdoors","land");
        
        setup();


 }
void init()
{
        add_action("do_search", "search");
}
void do_search(object me,string arg)
{

        if (arg != "草叢"  )
                return 0;
      else{
        message_vision( "$N仔細找了找附近的草叢，赫然發現一塊不尋常的大石！\n\n"  ,me);
         set("item_desc",([
        "大石":"這裡的大石上隱約看見幾行字「北斗之柄，生者向西，死者向東。」 \n
                                 ●     ●                                   \n
                                                                             \n
                ●         ●                     ●                         \n
                                                                             \n
                                                                             \n
                   ●      ●                                                \n
                                                                             \n
                 哇哩咧....這算什麼北斗七星啊.....-.-\n"       
         ]));
}
}
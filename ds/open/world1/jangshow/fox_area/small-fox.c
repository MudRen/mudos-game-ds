inherit NPC;

void create()
{
        set_name("小狐狸",({"small fox","fox"}));
        set("long","一種在凌雲寺常見的狐狸。\n");
        set("gender","雄");
        set("attitude", "peaceful");
        set("age",3);
       set("level",15);
        set("race","beast");
        set("chat_chance",7);
        set("chat_msg",({
          "小狐狸坐了下來，抓了抓癢，樣子十分可愛。\n", 
        (: random_move :),
         }) );
        setup();
}


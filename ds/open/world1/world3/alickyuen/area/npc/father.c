//updated 12/2
inherit NPC;
void create()
{
        set_name("神父",({"god-father","father"}) );
	set("long", "一位神父，正跪在地上向著神像祈禱。\n");
        set("age",60);
        set("level",10);
        set("gender","男");
        set("race","人類");
        set("chat_chance",10);
        set("chat_msg",({
"神父說道： 我們的天父，為你的名受顯揚；\n",
"神父說道：願你的國來臨;願你的旨意奉行在人間，如同在天上。\n",
"神父說道：求你今天賞給我們日用的食糧；\n",
"神父說道：求你寬恕我們的罪過，如同我們寬恕別人一樣；\n",
"神父說道：不要讓我們陷於誘惑，但救我們免於凶惡。\n",
"神父說道：『亞孟…』\n",
        }) );	
set("talk_reply","實在太可怕了.....還是繼續祈禱好......\n");
        setup();
carry_object(__DIR__"obj/note_book");
}

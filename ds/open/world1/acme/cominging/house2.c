inherit ROOM;

void create()
{
	set("short", "刑房");
	set("long", @LONG
這裡是平常執行對犯人處置的地方，在這裡有許多的殺人用具，就
像是虎頭鍘、鐵鞭、和烙塊都一應俱全，看來在這裡犯人日子並不怎麼
的好過，說不定那天被拖出來拷打，全身上下痛苦真是說不出來，在這
也有公堂中的鐵夾，專門用來夾人的手指，令人看到了不寒而顫。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path5",
]));
	set("no_clean_up", 0);
	set("item_desc",([
  "虎頭鍘" : "一個傳奇人物包青天常使用的工具，共有狗頭鍘等等分類，依序由犯罪的好壞分級，上面還沾了一點點的血。\n",
  "鐵鞭" : "由鐵所製成的鞭子，上面有一條條的鐵勾，若是被打到了，定有無法消失的疤痕。\n",
  "烙塊" : "熱騰騰的一塊鐵，常常用來拷打刑犯之用，因為太過狠毒，常常都是在拷問死囚時才用的到。\n",
"鐵夾" : "十大酷刑中的一種狠毒的方法，用來夾犯人手指的末端，讓人常痛的暈了過去，因為夾的地方是神經末梢，所以會感觸良多。\n",
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}

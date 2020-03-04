// junkman.c

inherit NPC;

void create()
{
	set_name("拾荒老頭", ({ "junkman" }));

	set("age", 66);

	set("long",
		"一個痀僂的拾荒老頭﹐靠撿拾廢物維生﹐如果你願意幫助這樣一個\n"
		"老人過好一點的生活﹐或者是願意替辛苦的巫師們節省一點記憶體\n"
		"﹐請把你身上多餘的東西給他。\n"
	  );

        set("chat_chance", 20);
        set("chat_msg", ({
                "捨荒老頭吆喝道﹕收∼破∼爛∼哪∼\n",
                "捨荒老頭的嘴裡嘟噥著﹐不知道說些什麼。\n",
                "捨荒老頭伸手捉住了身上的蝨子﹐一腳踩得扁扁的。 \n",
                (: random_move :)
        }) );
	setup();


	// Always flee.
	set("max_gin", 100);
	set("max_kee", 100);
	set("max_sen", 100);
}



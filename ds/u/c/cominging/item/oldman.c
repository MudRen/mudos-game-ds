#include <ansi.h>
inherit NPC;

void fireball();

void create()
{
        set_name("An old man"NOR, ({ "old man", "man" }));
        set("long", @LONG
What you look at is an old man with magic light.
You've felt much magical power near the man,
and he's still reading some books, he doesn't
mind your coming.
LONG    );
        set("title", HIY"The secret person"NOR);
        set("level", 40);
        set("combat_exp" ,2000);
        set("attitude", "peaceful");
        set("age", 70+random(30));
        set("chat_chance", 7);
        set("chat_msg", ({
  "You can hear the old man reading the book.\n",
  "There's fireball before your eyes.\n",
}));
        set("chat_change_combat", 20);
        set("chat_msg_combat", ({
  (: fireball :),
  "The old man shouts 'HELP ! HELP ME ! SOMEONE WANNA KILL ME !!!'"
}));
        set("inquiry", ([
  "new_words" : "paternoster �G�� susurrate ���ۻy",
]));
        setup();
        add_money("coin", 1000);
        carry_object(__DIR__"magic_book.c");

}

void fireball() // paternoster �G�� susurrate ���ۻy
{
        object *obs;
        int x;
        obs = all_inventory(environment(this_object()));
        message_vision(HIY"$N susurrates some paternosters, you can see "HIR"lots of fireballs"HIY" throws from him to all around", this_object());
        for(x=0;x<sizeof(obs);x++)
                if( interactive(obs[x]) )
                {
                        obs[x]->receive_damage("hp", random(100));
                        tell_object(obs[x], HIR"You've gotten hurt by the FIREBALL"NOR);
                }
        return;
}
        

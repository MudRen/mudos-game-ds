// ���Z�H �@��]�w By Tmr 2002/05/08

// prototypes
mixed do_chat(mixed chat);
varargs string name(int raw);
void kill_ob(object ob);
varargs int is_fighting(object ob);

int accept_fight(object ob)
{
        if( is_fighting() ) {
                return 0;
        }
        do_chat( name() + "�L�̼T���B�P�a�����b������A�M��u���L�ĤF�L��...\n");
        kill_ob(ob);
        return 1;
}

void accept_kill(object ob)
{
        do_chat( name() + "�g�q�@�n�A���S���������F�L�ӡI�I\n");
}


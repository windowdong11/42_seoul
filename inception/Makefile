COMPOSE_ARGS = --project-directory=srcs

.PHONY: all
all:
	mkdir -p /home/dowon/data/mariadb
	mkdir -p /home/dowon/data/wordpress
	docker compose $(COMPOSE_ARGS) up

.PHONY: clean
clean:
	docker compose $(COMPOSE_ARGS) down -v
	rm -rf /home/dowon/data/mariadb
	rm -rf /home/dowon/data/wordpress

.PHONY: down
down:
	docker compose $(COMPOSE_ARGS) down

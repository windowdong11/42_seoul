COMPOSE_ARGS = --project-directory=srcs

.PHONY: all
all:
	docker compose $(COMPOSE_ARGS) up

.PHONY: clean
clean:
	docker compose $(COMPOSE_ARGS) down -v

.PHONY: down
down:
	docker compose $(COMPOSE_ARGS) down

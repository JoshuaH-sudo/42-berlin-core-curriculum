setup:
	uv venv
	uv pip install pytest

test:
	uv run pytest

clean:
	find . -type d -name __pycache__ -exec rm -rf {} +
	find . -type d -name .pytest_cache -exec rm -rf {} +
	find . -name "*.pyc" -delete

fclean: clean
	rm -rf .venv

.PHONY: setup test clean fclean

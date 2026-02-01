# Contributing to DefinEngine

Thank you for your interest in contributing!

## Conventional Commits

We use [Conventional Commits](https://www.conventionalcommits.org/) to automate our versioning and release process.

### Commit Message Format

```
<type>(<scope>): <subject>

[optional body]

[optional footer(s)]
```

### Types

- `feat`: A new feature (MINOR version bump)
- `fix`: A bug fix (PATCH version bump)
- `docs`: Documentation only changes
- `style`: Changes that do not affect the meaning of the code
- `refactor`: A code change that neither fixes a bug nor adds a feature
- `perf`: A code change that improves performance
- `test`: Adding missing tests or correcting existing tests
- `build`: Changes that affect the build system or external dependencies
- `ci`: Changes to our CI configuration files and scripts
- `chore`: Other changes that don't modify src or test files

### Breaking Changes

Breaking changes MUST be indicated by a `!` after the type/scope or by a `BREAKING CHANGE:` footer. This will trigger a MAJOR version bump.

### Examples

- `feat(ui): add new main menu`
- `fix(core): resolve crash on startup`
- `feat(api)!: remove deprecated methods`
- `fix(renderer): minor glitch in shadow rendering [BREAKING CHANGE: changes shadow map format]`

## Pull Request Process

1. Ensure your code follows the existing style.
2. Update documentation if necessary.
3. Make sure all commits follow the conventional commit format.
4. Your PR will be automatically linted for commit message format.

workspace(name = "com_github_bazelboost_assert")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "boost",
    remote = "git@github.com:bazelboost/boost.git",
    branch = "develop",
)

load("@boost//:index.bzl", "boost_repositories")
boost_repositories()
